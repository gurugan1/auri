include("kNN.jl")

print("Loading training Data...\n")
trainData = readdlm("train.data", ',',Float64)
trainLabels = readdlm("trainLabels.csv",',',Int)

print("Loading test data... \n")
testData = readdlm("test.data",',',Float64)

pred = KNN.kNN(trainData, testData,trainLabels)
writecsv("results.csv",pred)


