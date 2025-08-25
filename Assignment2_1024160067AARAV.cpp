

#include <iostream>
using namespace std;

int main() {
    int n, target;
    int arr[100]; // assuming array is sorted

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> target;

    int low = 0;
    int high = n - 1;
    int result = -1;  // start with not found

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            result = mid; // update result
            break;
        } else if (arr[mid] < target) {
            low = mid + 1; // right half
        } else {
            high = mid - 1; // left half
        }
    }

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

/*2) 
64 34 25 12 22 11 90*/

#include <iostream>
using namespace std;

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*3) 
(a) Linear time
(b) Using binary search.*/

//a. 
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n (range 1 to n): ";
    cin >> n;

    int arr[n-1];
    cout << "Enter " << n-1 << " sorted elements: ";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    int missing = n; 
    for (int i = 0; i < n-1; i++) {
        if (arr[i] != i + 1) {
            missing = i + 1;
            break;
        }
    }

    cout << "Missing number is: " << missing << endl;
    return 0;
}

//b.
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "enter n (from 1 to n): ";
    cin >> n;

    int arr[n-1];
    cout << "enter " << n-1 << " sorted elements: ";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    int low = 0, high = n - 2; 
    int missing = n; 

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            missing = mid + 1;
            high = mid - 1;
        }
    }

    cout << "missing number is: " << missing << endl;
    return 0;
}

/*4) String Related Programs
(a) Write a program to concatenate one string to another string.
(b) Write a program to reverse a string.
(c) Write a program to delete all the vowels from the string.
(d) Write a program to sort the strings in alphabetical order.
(e) Write a program to convert a character from uppercase to lowercase.*/

//a.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    string str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    string concat = str1 + str2;

    cout << "Concatenated string: " << concat << endl;
    return 0;
}

//b.
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    int n = strlen(str);
    for (int i = 0; i < n/2; i++) {
        char temp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = temp;
    }

    cout << "Reversed string: " << str << endl;
    return 0;
}

//c.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, result = "";
    
    cout << "enter a string: ";
    cin>>str;

    for(int i = 0; i < str.length(); i++) {
        char c = tolower(str[i]); 
        if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u') {
            result += str[i];   
        }
    }

    cout << "new string: " << result;
    return 0;
}

//d.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "enter a string: ";
    cin >> str;

    int n = str.length();

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(str[j] > str[j+1]) {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }

    cout << "sorted word: " << str << endl;
    return 0;
}

//e.
#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }

    cout << "Lowercase string: " << str << endl;
    return 0;
}

/*5) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(a) Diagonal Matrix.
(b) Tri-diagonal Matrix.
(c) Lower triangular Matrix.
(d) Upper triangular Matrix.
(e) Symmetric Matrix*/

//a. Diagonal Matrix
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int diag[n]; 

    for(int i=0; i<n; i++) {
        diag[i] = (i+1)*10;
    }

    cout << "Diagonal Matrix:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j){
                cout << diag[i] << " ";
            } 
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

//b. Tri Diagonal Matrix 
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int tri[3*n-2]; 

    for(int i=0; i<n; i++){
        tri[i] = 1*(i+1); //main
    }       
    for(int i=0; i<n-1; i++){
        tri[n+i] = 1+i; // upper
    }       
    for(int i=0; i<n-1; i++){
        tri[2*n-1+i] = 2+i; //lower
    }    

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) cout << tri[i] << " ";                 // main
            else if(j==i+1) cout << tri[n+i] << " ";        // upper
            else if(i==j+1) cout << tri[2*n-1+(j)] << " ";  // lower
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

//c. Lower triangular matrix
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int lower[n*(n+1)/2];

    int k=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            lower[k++] = (i+1)*1 + j;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i>=j) cout << lower[(i*(i+1))/2 + j] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

//d. Upper Triangular Matrix
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int upper[n*(n+1)/2];
    
    int k=0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            upper[k++] = (i+1)*1 + j;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i<=j) cout << upper[i*n - (i*(i-1))/2 + (j-i)] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

//e. Symmetric Matrix
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int sym[n*(n+1)/2];
    
    int k=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            sym[k++] = (i+1)*1 + j;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i>=j) cout << sym[(i*(i+1))/2 + j] << " ";
            else cout << sym[(j*(j+1))/2 + i] << " "; 
        }
        cout << endl;
    }
}

/*6) Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices.*/

//a.Transpose
#include <iostream>
using namespace std;

int main() {
    int m;
    int n;
    int t;
    
    cout << "enter rows: ";
    cin>>m;
    cout<<"enter cols: ";
    cin>>n;
    cout<< "enter non-zero elements: ";
    cin>>t;

    int a[100][3];  
    cout << "enter triplet :\n";
    for (int i = 0; i < t; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    cout << "transpose: \n";
    for (int i = 0; i < t; i++) {
        cout << a[i][1] << " " << a[i][0] << " " << a[i][2] << endl;
    }

    return 0;
}

//b. Addition


//c. Multiplication
#include <iostream>
using namespace std;

int main() {
    int t1, t2;
    cout << "enter non zero elements in A: ";
    cin >> t1;
    int A[t1][3];   
    cout << "enter triplet for A: ";
    for (int i = 0; i < t1; i++) 
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "enter non zero elements in B: ";
    cin >> t2;
    int B[t2][3]; 
    cout << "enter triplet for B: \n";
    for (int i = 0; i < t2; i++) 
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    cout << "multiplication of A and B: \n";
    for (int i = 0; i < t1; i++) {
        for (int j = 0; j < t2; j++) {
            if (A[i][1] == B[j][0]) {  // colA = rowB
                cout << A[i][0] << " " << B[j][1] << " " 
                     << A[i][2] * B[j][2] << endl;
            }
        }
    }

    return 0;
}

/*7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an
inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to
count the number of inversions in an array.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "enter size of array: ";
    cin >> n;

    int A[n];
    cout << "enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                count++;
            }
        }
    }

    cout << "number of inversions: " << count << endl;
    return 0;
}

/*8) Write a program to count the total number of distinct elements in an array of length
n.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isDistinct = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) count++;
    }

    cout << "total number of distinct elements: " << count << endl;

    return 0;
}
