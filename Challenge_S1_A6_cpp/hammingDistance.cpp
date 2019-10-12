#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
string binaryOf(char x)
{
    int ascii_value = (int)x;
    string binary = "";
    while(ascii_value!=0)
    {
        int rem = ascii_value%2;
        ascii_value = ascii_value/2;
        if(rem==1)
            binary = binary + "1";
        else
            binary = binary + "0";
    }
    while(binary.length()!=8)
        binary = binary + "0";
    reverse(binary.begin(), binary.end());
    return binary;
}
string* convertToBinary(string a)
{
    string* binary;
    binary = new string[a.length()];
    for(int i = 0; i<a.length(); ++i)
    {
        binary[i] = binaryOf(a[i]);
    }
    return binary;
}
int hammingDistance(string a, string b)
{
    int hamming = 0;
    if(a.length()!=b.length())
        cout<<"ERROR : LENGTH MISMATCH"<<endl;
    string* binary_a = convertToBinary(a);
    string* binary_b = convertToBinary(b);
    cout<<"Binary Conversion Complete"<<endl;
    cout<<"Binary Conversion of string = "<<a<<" is ";
    for(int i=0; i<a.length(); ++i)
    {
        cout<<binary_a[i]<<" ";
    }
    cout<<endl;
    cout<<"Binary conversion of string = "<<b<<" is ";
    for(int i=0; i<a.length(); ++i)
    {
        cout<<binary_b[i]<<" ";
        string currentString1 = binary_a[i], currentString2 = binary_b[i];
        for(int j=0; j<currentString1.length(); ++j)
        {
            if(currentString1[j]!=currentString2[j])
                hamming++;
        }
    }
    cout<<endl;
    return hamming;
}
