#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <math.h>
#include "minmax.h"
#include <cctype>
using std::to_string;
using std::atoi;
using std::cout;
using std::string;
using std::vector;
using std::stringstream;

    int Minmax::getParent(int index)
    {
        return(floor((index-1)/2));
    }
    int Minmax::getLeftChild(int index)
    {
        return(2*index+1);
    }
    int Minmax::getRightChild(int index)
    {
        return(2*index+2);
    }

    bool Minmax::onMaxLevel(int index)
    {
        return(int(log2(index+1))%2 == 1);
    }
    bool Minmax::onMinLevel(int index)
    {
        return(!onMaxLevel(index));
    }

    void Minmax::trickleDown(int index)
    {
	if(index < (size-1))
	{
            if(onMinLevel(index))
                trickleDownMin(index);
            else if(onMaxLevel(index))
            	trickleDownMax(index);
	}
	return;
    }

    void Minmax::trickleDownMin(int index)
    {
        int m;
        int descendants[6];
	int descIndex[6];
        bool isGrandChild;
	//cout << size;
	int descSize = 0;
	//cout << "in trickedownmin";
        if (getLeftChild(index) < (size-1))
        {
	    //cout << "in first if";
            descendants[descSize] = A[getLeftChild(index)];
	    descIndex[descSize] = getLeftChild(index);
	    descSize++;
        
            if(getRightChild(index) < (size-1))
            {
                descendants[descSize] = A[getRightChild(index)];
		    descIndex[descSize] = getRightChild(index);
		descSize++;

                //grandchildren can only exist if there are two children for the passed index
                if(getLeftChild(getLeftChild(index)) < (size-1))
                {
                    descendants[descSize] = A[getLeftChild(getLeftChild(index))];
			descIndex[descSize] = getLeftChild(getLeftChild(index));
		    descSize++;
                }
                if(getRightChild(getLeftChild(index)) < (size-1))
                {
                    descendants[descSize] = A[getRightChild(getLeftChild(index))];
			descIndex[descSize] = getRightChild(getLeftChild(index));
		    descSize++;
                }
                if(getLeftChild(getRightChild(index)) < (size - 1))
                {
                    descendants[descSize] = A[getLeftChild(getRightChild(index))];
			descIndex[descSize] = getLeftChild(getRightChild(index));
		    descSize++;
                }
                if(getRightChild(getRightChild(index)) < (size-1))
                {
                    descendants[descSize] = A[getRightChild(getRightChild(index))];
			descIndex[descSize] = getRightChild(getRightChild(index));
		    descSize++;
                }
            }
	    m = 0;
	    int indexOfMin = 0;
            for(int i = 0; i<descSize;i++){ //get minimum from children and grandchildren, stored in an array
                
		//cout << "in for loop";
		//cout << "this is the " << i << " " << descendants[i]<<std::endl;
                     
                    if(descendants[i] < descendants[m])
                    {
                        m = i;
                        if(m > 1)
                            isGrandChild = true;
                        else
                            isGrandChild = false;
			indexOfMin = descIndex[i];
                    }
		    //cout<<"descendants[m] the min is " << descendants[m] << std::endl;
		    //cout<<"descendants[m] is grandchild? " << isGrandChild << std::endl;
                
            }
            if(isGrandChild){
                if(A[indexOfMin] < A[index])
                {
                    int temp = A[indexOfMin];
                    A[indexOfMin] = A[index];
                    A[index] = temp;
                    if(A[indexOfMin] > A[getParent(indexOfMin)])
                    {
                        int temp = A[indexOfMin];
                        A[index] = A[getParent(indexOfMin)];
                        A[getParent(indexOfMin)] = A[index];

                    }
                        trickleDownMin(indexOfMin);
                }

            }
            else
                if(A[indexOfMin] < A[index]){ //swap A[m] and A[i]
                    int temp = A[indexOfMin];
                    A[indexOfMin] = A[index];
                    A[index] = temp;
			//trickleDownMax(index);
                }
        }

    }


   void Minmax::trickleDownMax(int index)
    {
        int m;
        int descendants[6];
	int descIndex[6];
        bool isGrandChild;
	//cout << size;
	int descSize = 0;
	//cout << "in trickedownmin";
        if (getLeftChild(index) < (size-1))
        {
	    //cout << "in first if";
            descendants[descSize] = A[getLeftChild(index)];
	    descIndex[descSize] = getLeftChild(index);
	    descSize++;
        
            if(getRightChild(index) < (size-1))
            {
                descendants[descSize] = A[getRightChild(index)];
		    descIndex[descSize] = getRightChild(index);
		descSize++;

                //grandchildren can only exist if there are two children for the passed index
                if(getLeftChild(getLeftChild(index)) < (size-1))
                {
                    descendants[descSize] = A[getLeftChild(getLeftChild(index))];
			descIndex[descSize] = getLeftChild(getLeftChild(index));
		    descSize++;
                }
                if(getRightChild(getLeftChild(index)) < (size-1))
                {
                    descendants[descSize] = A[getRightChild(getLeftChild(index))];
			descIndex[descSize] = getRightChild(getLeftChild(index));
		    descSize++;
                }
                if(getLeftChild(getRightChild(index)) < (size - 1))
                {
                    descendants[descSize] = A[getLeftChild(getRightChild(index))];
			descIndex[descSize] = getLeftChild(getRightChild(index));
		    descSize++;
                }
                if(getRightChild(getRightChild(index)) < (size-1))
                {
                    descendants[descSize] = A[getRightChild(getRightChild(index))];
			descIndex[descSize] = getRightChild(getRightChild(index));
		    descSize++;
                }
            }
	    m = 0;
	    int indexOfMin = 0;
            for(int i = 0; i<descSize;i++){ //get minimum from children and grandchildren, stored in an array
                
		//cout << "in for loop";
		//cout << "this is the " << i << " " << descendants[i]<<std::endl;
                     
                    if(descendants[i] < descendants[m])
                    {
                        m = i;
                        if(m > 1)
                            isGrandChild = true;
                        else
                            isGrandChild = false;
			indexOfMin = descIndex[i];
                    }
		    //cout<<"descendants[m] the min is " << descendants[m] << std::endl;
		    //cout<<"descendants[m] is grandchild? " << isGrandChild << std::endl;
                
            }
            if(isGrandChild){
                if(A[indexOfMin] > A[index])
                {
                    int temp = A[indexOfMin];
                    A[indexOfMin] = A[index];
                    A[index] = temp;
                    if(A[indexOfMin] < A[getParent(indexOfMin)])
                    {
                        int temp = A[indexOfMin];
                        A[indexOfMin] = A[getParent(indexOfMin)];
                        A[getParent(indexOfMin)] = A[indexOfMin];
                    }
                    trickleDownMax(indexOfMin);
                }

            }
            else
                if(A[indexOfMin] > A[index]){ //swap A[m] and A[i]
                    int temp = A[indexOfMin];
                    A[indexOfMin] = A[index];
                    A[index] = temp;
		    //trickleDownMin(indexOfMin);
                }
        }

    }

    void Minmax::bubbleUp(int index)
    {
        if(onMinLevel(index))
        {
            if((index != 0) && (A[index] > A[getParent(index)]))
            {
                int temp = A[index];
                A[index] = A[getParent(index)];
                A[getParent(index)] = temp;
                bubbleUpMax(getParent(index));
            }
            else
                bubbleUpMin(index);
        }
        else 
        {
	    if((index != 0) && (A[index] < A[getParent(index)]))
	    {
		    int temp = A[index];
		    A[index] = A[getParent(index)];
		    A[getParent(index)] = temp;
		    bubbleUpMin(getParent(index));
	    }
	    else
                bubbleUpMax(index);
        }
        
    }

    void Minmax::bubbleUpMin(int index)
    {
        if(getParent(index) != 0)
        {
            if(A[index] < A[getParent(getParent(index))])
            {
                int temp = A[index];
                A[index] = A[getParent(getParent(index))];
                A[getParent(getParent(index))] = temp;
                bubbleUpMin(getParent(getParent(index)));
            }
        }
    }

    void Minmax::bubbleUpMax(int index)
    {
        if(getParent(index) != 0)
        {
            if(A[index] > A[getParent(getParent(index))])
            {
                int temp = A[index];
                A[index] = A[getParent(getParent(index))];
                A[getParent(getParent(index))] = temp;
                bubbleUpMax(getParent(getParent(index)));
            }
        }
    }

    int Minmax::insert(int value)
    {
        A[size] = value;
        bubbleUp(size);
	//cout << "asfter insertion " << A[size];
        size++;
        return value;
    }

    string Minmax::getMax()
    {
	//cout << "in minmax getmax";
        string results;
	int max;
        if(size == 0){
	   // cout << "returned 0";
            return "0";
	}
	//cout << "past if 1";
        if(A[1] > A[2])
            max =  A[1];
	//cout << "past if 2";
	else
            max = A[2];
	//cout << "value of max is " << max;
	results = "max = " + to_string(max);
	//cout << results;
        return results;
    }
    string Minmax::getMin()
    {
        if(size == 0)
            return "0";
        return "min = " + to_string(A[0]);
    }

    string Minmax::deleteMin()
    {
        int min = A[0];
        A[0] = A[size-1];
        A[size-1] = 0;
        size--;
	//cout <<"new A0 is "<< A[0]<<std::endl;
        trickleDown(0);
        return "deleted " + to_string(min);

    }
    string Minmax::deleteMax()
    {
        int maxIndex;
        int max;
        if(size == 0)
            return "0";
        if(A[1] > A[2])
            maxIndex =  1;
	else
            maxIndex = 2;
        max = A[maxIndex];
        A[maxIndex] = A[size-1];
        A[size-1] = 0;
        size--;
        trickleDown(maxIndex);
        return "deleted " + to_string(max);
    }

    void Minmax::printHeap()
    {
        cout << "heap = ";
        for(int i = 0; i < size; i++)
        {
            cout << A[i] << " ";
        }
    }

    int Minmax::getInt(string command)
    {
        /*stringstream ss;
        ss << command;

        string temp;
        int found;
        int value; 
	cout << "1";
        while(!ss.eof())
        {
	    cout << "2";
            ss >> command;
            if(stringstream(temp) >> found){
                cout << found << " ";
		cout << "3";
	    }
	        //value = found;
        }
	cout << "4";
        return value;*/
	        int i = 0;
	        bool isNeg = false;
		for(; i < command.length(); i++)
		{
			if(isdigit(command[i])) 
			{
			    if(command[i-1] == '-')
				    isNeg = true;
			    break;
			}
		}
		command = command.substr(i, command.length() - i);
	        int seperate;
	        seperate = atoi(command.c_str());
	        if(isNeg)
			seperate = seperate - 2*seperate;
		return seperate;
	
    }
