module MLNaiveBayes

function logPrior( trainLabels )
    num_unique_labels  = length(unique(collect(trainLabels)))
    num_docs = length(trainLabels)
    prior = zeros(Float64,num_unique_labels)

    
    for i in trainLabels
        prior[i]+=1
    end

    for i=1:num_unique_labels
        prior[i] = log(prior[i]/num_docs)
    end
    return prior 
end

function logLikelihood( trainData, trainLabels )
    n = length(unique(collect(trainData[:,2])))
    pn = length(unique(collect(trainLabels)))
    ret = ones(Float64,n,pn)
    @printf("n is %d and pn is %d\n",n,pn)
    for i=1:size(trainData,1)
        docId = trainData[i,1]
        term = trainData[i,2]
        termcount = trainData[i,3]
        label = trainLabels[docId]
        ret[term,label]+= termcount
    end
    for j = 1:pn
        logj = log(sum(ret[:,j]))
        for i = 1:n
            ret[i,j] = log(ret[i,j]) - logj
        end
    end
    return ret
end

function naiveBayesClassify( prior, likelihood, testData )
    n = size(likelihood,1)
    m = size(prior,1)
    
    dn = length(unique(collect(testData[:,1])))
    label_prob = zeros(Float64,dn,m)
    for i=1:size(testData,1)
        docId = testData[i,1]
        term = testData[i,2]
        termcount = testData[i,3]
        if term<=n && termcount>0 
            for j= 1:m
                label_prob[docId,j] += likelihood[term,j]
            end
        end
    end

    ret = zeros(Float64,dn)
    for i = 1:dn
        best = log(0)
        ret[i]=1
        for j = 1:m
            if best < label_prob[i,j]+prior[j]
                best = label_prob[i,j] + prior[j]
                ret[i] = j
            end
        end
    end
    return ret
end

end

