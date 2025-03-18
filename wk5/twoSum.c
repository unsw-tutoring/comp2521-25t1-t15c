#include <stdbool.h>
#include <stdio.h>

#include "BST.h"

// return whether there are two numbers in the array that sum to 'sum'
// n = size of the array
// O(n^2) solution
// 1,2,3,4,5; target = 9 -> true
// 1,2,3,4,5; target = 10 -> false
bool hasTwoSum(int *arr, int n, int sum) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                return true;
            }
        }
    }
    return false;
}

// use a binary search tree
bool hasTwoSum(int *arr, int n, int sum) {
    // create a new BST
    BSTree bst = BSTNew();
    // for each number
    for (int i = 0; i < n; i++) {
        // check if complement is in BST
        int complement = sum - arr[i];
        if (BSTSearch(bst, complement)) {
            BSTFree(bst);
            return true;
        }

        // insert in bST
        BSTInsert(bst, arr[i]);
    }
    BSTFree(bst);
    return false;
}
