int getNthFib(int n) {

	if (n<1) 
		return -1;

	int oddTerm 	= 0;
	int evenTerm 	= 1;

	for (int i = 1; i <= n-2; ++i)
	{
		if (i%2==1) 
			oddTerm += evenTerm;
		else 		
			evenTerm += oddTerm;
	}

	if (n%2==1) 
		return oddTerm;
	else 		
		return evenTerm;
}