class segTree{

private:
	long long size,MAX_ST,h; // size = 실제 arr값 바로 아래부터, MAX_ST = Segment Tree size, h = height
	vector<long long> arr; // Segment Tree

public:
	long long sum(int L, int R){ // Root Sum
		if(R < 1 || size < L) return 0; // 해당 node가 구간 [1,size]을 포함하지 않음
		if(L <= 1 && size <= R) return arr[1]; // 해당 node가 [1,size]을 완전히 포함
		int mid = (1 + size)/2;
		return sum(L, R, 1*2, 1, mid) +
			   sum(L, R, 1*2+1, mid+1,size); // 양 옆으로 나눠서 다시 탐색
	}

	long long sum(int L, int R, int nodeNum, int nodeL, int nodeR){ // nodeNum sum
		if(R < nodeL || nodeR < L) return 0; // 해당 node가 구간 [L,R]을 포함하지 않음
		if(L <= nodeL && nodeR <= R) return arr[nodeNum]; // 해당 node가 [L,R]을 완전히 포함
		int mid = (nodeL + nodeR)/2;
		return sum(L, R, nodeNum*2, nodeL, mid) +
			   sum(L, R, nodeNum*2+1, mid+1,nodeR); // 양 옆으로 나눠서 다시 탐색
	}

	void insert(int idx,int val){ // idx 위치에 value값 insert
		arr[idx+size] = val;
	}

	void update(int idx,int val){ // idx 위치에 value값으로 바꾸고 Segment Tree를 update
		idx += size;
		arr[idx] = val;
		while(idx > 1){
			idx /= 2;
			arr[idx] = arr[idx*2] + arr[idx*2+1];
		}
	}

	void construct(){ // size+1 부터 MAX_ST까지 들어간 실제 arr값을 Segment Tree로 Update
		for(int i=size;i>0;--i){
			arr[i] = arr[i*2] + arr[i*2+1];
		}
	}
	
	void print(){ // 모든 Segment Tree값 Print
		for(int i=1;i<=MAX_ST;i++){
			printf("%lld ",arr[i]);
		}
		printf("\n");
	}

	segTree(int arrsize){ // n 개 원소를 가진 arr의 Segment Tree Constructor
		this->h = ceil(log2(arrsize));
		this->size = 1 << h;
		this->MAX_ST = size << 1;
		this->arr.resize(MAX_ST);
		this->size--;
	}
};
