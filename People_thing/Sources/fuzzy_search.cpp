#include "pch.h"
#include "..\Headers\typedefs.h"
#include "../Headers/fuzzy_search.h"

bool levenshtein_distance( const std::string string1, const std::string string2 )
{
	int d[100][100];
#define MIN(x,y) ((x) < (y) ? (x) : (y))
	int i, j, m, n, temp, tracker;
	const int s1 = string1.length();
	const int s2 = string2.length();

	char* char_array1 = new char[s1 + 1];
	char* char_array2 = new char[s2 + 1];

	strncpy( char_array1, string1.c_str(), sizeof( char_array1 ) );
	strncpy( char_array2, string2.c_str(), sizeof( char_array2 ) );

	m = s1;
	n = s2;

	for ( i = 0; i <= m; i++ )
		d[0][i] = i;
	for ( j = 0; j <= n; j++ )
		d[j][0] = j;

	for ( j = 1; j <= m; j++ )
	{
		for ( i = 1; i <= n; i++ )
		{
			if ( char_array1[i - 1] == char_array2[j - 1] )
			{
				tracker = 0;
			}
			else
			{
				tracker = 1;
			}
			temp = MIN( (d[i - 1][j] + 1), (d[i][j - 1] + 1) );
			d[i][j] = MIN( temp, (d[i - 1][j - 1] + tracker) );
		}
	}
	//printf("the Levinstein distance is %d\n", d[n][m]);

	if ( d[n][m] <= 2 )
	{
		return true;
	}
	else
	{
		return false;
	}

}
