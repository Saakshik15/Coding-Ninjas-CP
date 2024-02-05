// Problem statement
// According to counting sort, which line is not correct?

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
        cin >> a[i];
  int maxi = *max_element(a.begin(), a.end());
  int mini = *min_element(a.begin(), a.end());
  vector<int> f(maxi - mini + 2);//Statement A

  for (int i = 0; i < n; i++)
  {
        f[(a[i] - mini)++];//Statement B
  }

  for (int i = 0; i < f.size(); i++)
  {
        for (int j = 0; j < f[i]; j++)
        {
              cout << (i + mini) << " ";// Statement C
        }
  }
}

// ans:
// statement B -> f[a[i]-mini]++ is correct statement.
