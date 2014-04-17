
include("naivebayes.jl")

print("Loading training data...\n")
trainData = readdlm("../data/train.data", ' ', Int)
trainLabels = readdlm("../data/train.label", ' ', Int)

print("Loading testing data...\n")
testData = readdlm("../data/test.data", ' ', Int)
testLabels = readdlm("../data/test.label", ' ', Int)

print("Computing log prior...\n")
lp = MLNaiveBayes.logPrior(trainLabels)
writecsv("logPrior.csv", lp)

print("Computing log likelihood...\n")
llh = MLNaiveBayes.logLikelihood(trainData, trainLabels)
writecsv("logLikelihood.csv", llh)

print("Classifying using Naive Bayes...\n")
pred = MLNaiveBayes.naiveBayesClassify(lp, llh, testData)
writecsv("nbResults.csv", pred)

res = (pred .== testLabels)
accuracy = length(res[res]) / length(res) * 100
@printf("Accuracy is %0.2f\n", accuracy)

