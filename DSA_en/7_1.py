
"""
1. 将当前数值拼接到前面的结果后面。
2. 当前数值从头开始。
"""
def main():
    n = int(input())
    arr = [int(x) for x in input().split()]
    maxSum = -1
    tempSum = 0
    tempL = 0
    tempR = 0
    maxL = -1
    maxR = -1
    n = len(arr)
    for i in range(n):
        tempSum += arr[i]
        tempR = i; 
        if tempSum>maxSum:
            maxSum = tempSum
            maxL = tempL
            maxR = tempR
        if tempSum<0:
            tempSum = 0
            tempL = i+1
            tempR = i+1
    
    if maxSum<0:
        print("0 {} {}".format(arr[0], arr[n-1]));
    else:
        print("{} {} {}".format(maxSum, arr[maxL], arr[maxR]));
main()