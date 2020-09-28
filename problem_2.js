// Maximal Contiguous Sum

// Implement a function maxContSum(array) in JavaScript to find the largest con-
// tiguous subsequence of an array. As an example, the array [0, -3, 2, 1, 4,
// 5, 9, -3, 2] has the maximal contiguous sum of 21, because the contiguous
// subarray [2, 1, 4, 5, 9] has the largest sum of any contiguous subarray.

const maxContSum = (arr) => {
    let currentSum = 0
    let largestSum = arr[0]
    arr.forEach(i => {
        if (currentSum < 0) {
            currentSum = i; // negative sums cannot be part of maximum subarray, overwrite
        } else {
            currentSum = currentSum + i; // add and proceed
        }

        if (largestSum < currentSum) {
            largestSum = currentSum;
        }
    })
    return largestSum
}

const testMaxContSum = () => {
    testArr1 = [0, -3, 2, 1, 4, 5, 9, -3, 2];
    console.log(maxContSum(testArr1) === 21);

    testArr2 = [3, 3, 3, 3, -1, 9, -1];
    console.log(maxContSum(testArr2) === 20);

    testArr3 = [1, 2, -3, 999];
    console.log(maxContSum(testArr3) == 999);
}

testMaxContSum();
