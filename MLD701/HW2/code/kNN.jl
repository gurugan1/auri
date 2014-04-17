module KNN

function metric_one(cand,cur)
    n = size(cand,2)
    ret = 0
    for i=1:n
        ret += abs(cand[i]-cur[i])
    end
    return ret
end

function metric_two(cand,cur)
    n = size(cand,2)
    temp = zeros(Float64,n)
    for i = 1:n
        temp[i]= -abs(cand[i]-cur[i])
    end
    p = 5
    ret=0
    Base.Collections.heapify!(temp)
    for i =1:p
        ret-= Base.Collections.heappop!(temp)
    end
    return ret
end

    

function kNN(trainData, testData,trainLabel)
    n = size(trainData,1)
    @printf("Dimensions are%d\n",size(trainData,2))
    m = size(testData,1)
    k = 3 
    L = zeros(Int,k)
    label = zeros(Int,m,2)
    @printf("%d %d\n",n,m)
    totalone=0.0
    metric_one_use = 1
    if (metric_one_use ==1)
        @printf("Running metric one\n")
    else
        @printf("Running metric two\n")
    end
    for i = 1:m
        cur = testData[i,:]
        PQ = Base.Collections.PriorityQueue{Int,Float64}()
        for j  = 1:n
            cand = trainData[j,:]
            if (metric_one_use==1)
                curd = metric_one(cand,cur)
            else
                curd = metric_two(cand,cur)
            end

            PQ[j]=curd
        end
        total = 0
        for j = 1:k
            L[j]= Base.Collections.peek(PQ)[1]
            PQ[L[j]]= 9999999999
            total += (2*trainLabel[L[j],2]-1)
        end
        #@printf("%d %d\n",i,total)
        label[i,1]=i
        if (total*2 >= 0)
            label[i,2]=1
            totalone+=1
        end
    end
    @printf("Percentage of one is %.2lf %.2lf %d",totalone/m,totalone,m)
    return label
end



end


