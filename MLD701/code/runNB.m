
clear;

fprintf('Loading training data...\n');
trainData = load('../data/train.data');
trainLabels = load('../data/train.label');

fprintf('Loading testing data...\n');
testData = load('../data/test.data');
testLabels = load('../data/test.label');

fprintf('Computing log prior...\n');
lp = logPrior(trainLabels);
csvwrite('logPrior.csv', lp);

fprintf('Computing log likelihood...\n');
llh = logLikelihood(trainData, trainLabels);
csvwrite('logLikelihood.csv', llh);

fprintf('Classifying using Naive Bayes...\n');
pred = naiveBayesClassify(lp, llh, testData);
csvwrite('nbResults.csv', pred);

res = (pred == testLabels);
accuracy = numel(res(res == 1)) / numel(res) * 100;
fprintf('Accuracy is %0.2f\n', accuracy);
