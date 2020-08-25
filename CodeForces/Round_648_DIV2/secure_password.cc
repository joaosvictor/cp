#include
using namespace std;

#define ll long long
#define vint vector< int >

const int Q = 13;

ll query(vint v){
	cout << "? " << v.size() << ' ';
	for(ll i : v)
		cout << i + 1 << ' ';
	cout << endl;
	fflush(stdout);
	ll or_value;
	cin >> or_value;
	return or_value;
}

int main(){
	int n;
	cin >> n;

	vector< vint > ask(Q);
	vint assign_mask(n);

	vector< ll > or_value(Q), answer(n);

	int assigned = 0;

	for(int i = 1; i < (1 << Q); i++){
		if(__builtin_popcount(i) != Q / 2)
			continue;
		assign_mask[assigned] = i;
		for(int j = 0; j < Q; j++)
			if((i >> j & 1) == 0)
				ask[j].push_back(assigned);
		assigned++;
		if(assigned == n)
			break;
	}

	for(int i = 0; i < Q; i++)
		if(!ask[i].empty())
			or_value[i] = query(ask[i]);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < Q; j++)
			if(assign_mask[i] >> j & 1)
				answer[i] |= or_value[j];

	cout << "! ";

	for(ll i : answer)
		cout << i << ' ';

	cout << endl;
}
