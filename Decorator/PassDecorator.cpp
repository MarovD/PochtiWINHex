#include <iostream>
#include "PassDecorator.h"

Iterator Diterator;

	PassDecorator::PassDecorator(Iterator iterator){
		Diterator=iterator;
		File=iterator.File;
		end=File.countCluster;
		First();
		End();
	}


	bool PassDecorator::GetCurrent(byte *dataBuffer){
	if(Diterator.GetCurrent(dataBuffer))
		{
            for(int i=0;i<512;i++)
			{
			if(dataBuffer[i]!=0)
			   return true;
			}
			return false;

		}
	}






