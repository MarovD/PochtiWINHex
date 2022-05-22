#include <iostream>
#include "Iterator.h"

	Iterator::Iterator(FileSystem file){
	 File=file;
	 byte *dataBuffer = new byte[File.clusterSize];
	 end=File.countCluster;
     First();
	 End();

	}

	void Iterator::SetPosition(unsigned long position){
		if (position<end)
			Position=position;
	}

	void Iterator::SetDone(unsigned long count){
		if(Position+count<=end && count>0)
			Done=Position+count-1;
	}

	void Iterator::First(){
       Position=0;
	}

	void Iterator::End(){
      Done=end;
	}

	void Iterator::Next(){
	  Position++;
	}

	bool Iterator::IsDone(){
	if(Position>Done)
	return true;
	else
    return false;
	}

	bool Iterator::GetCurrent(byte *dataBuffer){
		return File.ReedCluster(Position,dataBuffer);
	}





