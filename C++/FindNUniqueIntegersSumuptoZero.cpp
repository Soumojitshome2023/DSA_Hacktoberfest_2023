class Solution {
public:

	vector<int> sumZero(int n) {
		vector<int>v;
		if(n&1){
			v.push_back(0);
			n/=2;
			for(int i=0; i<n; i++){
				v.push_back(i+1);
				v.push_back((-1)*(i+1));
			}
		}
		else{
			n/=2;
			for(int i=0; i<n; i++){
				v.push_back(i+1);
				v.push_back((-1)*(i+1));
			}
		}
		return v;
	}
};
