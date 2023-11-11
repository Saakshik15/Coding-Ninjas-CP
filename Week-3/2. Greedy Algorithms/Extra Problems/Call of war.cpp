/*
DecenTile Games have launched a new First Person Shooter soldier game, called the Call of War, that young gamers can play on their website.

Our protagonist, Ninja (played by you) is a soldier whose mission is to kill all the enemies plotting against you. 
Your enemies are standing in a circle, numbered clockwise from 1 to n. Initially, the i-th enemy has ai health.
You have only one pistol, and infinite bullet magazines. You have to shoot the enemies in order to kill them. 
Each bullet fired at the enemy decreases their health by 1 (deals 1 damage to it). When the health of some 
enemy i becomes 0 or less than 0, he dies and his grenade drops down and explodes, dealing bi damage to the 
next enemy (enemy  i+1, if i&lt;n, or enemy 1, if i=n). If the next enemy is already dead, then nothing happens. 
If the frag from the grenade kills the next enemy, even he drops a grenade, damaging the enemy after him and possibly 
triggering another explosion, and so on.
You have to calculate the minimum number of bullets you need in order to kill all the enemies and win the game.
*/


//code:

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fr(i,a,b) for(int i=a; i<b; i++)
#define loop(x,n) for(int x=0; x<n; ++x)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()

using namespace std;

void precal(){

}

void solve() {
	int n; cin >> n;
	vector<pair<ll, ll>> a(n);
	for(ll i = 0 ; i < n ; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	vector<pair<ll, ll>> v;
	for(ll i = 1 ; i < n ; ++i) {
		ll pts = min(a[i].first, a[i-1].second) - min(a[0].first, a[n-1].second);
		v.push_back({pts, i});
	}
	sort(v.begin(), v.end());

	ll index = 0;
	if(v.size() > 0 && v[0].first < 0) {
		index = v[0].second;
	}

	ll ans = 0;

	for(ll i = 0 ; i < n ; ++i) {
		ans += a[index].first;
		ll damage = a[index].second;

		index = (n + index + 1) % n;

		a[index].first = max(0LL, a[index].first - damage);
	}
	cout << ans << '\n';
}

int main(){

  fast_io;
  cout<<fixed;
  cout<< setprecision(10);
  precal();
  int t=1;
  cin >>t;
  for(int i=1; i<=t; i++){
    //cout<< "Case #" << i << ": ";
    solve();
  }

  return 0;
}
