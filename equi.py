
str1 = "7135";
str2 = "135";


# def editDistDP(str1, str2, m, n):
#     w = m+1
#     h = n+1
#     dp = [[0 for x in range(w)] for y in range(h)] 
#     print dp
#     for i in range(0,m+1):
#         for j in range(0,n+1):
#             print i,j
#             print dp
#             if (i==0 and j >= 1):
#                 dp[i][j] = dp[i][j-1] + int(str2[j-1]);  
            
#             elif (j==0 and i >= 1):
#                 dp[i][j] = dp[i-1][j] + int(str1[i-1]); 
 
#             elif (str1[i-1] == str2[j-1] and i != 0 and j != 0):
#                 dp[i][j] = dp[i-1][j-1];
#             else:
#                 dp[i][j] = min( dp[i][j-1] + (int(str2[j-1])),  
#                                    dp[i-1][j] + (int(str1[i-1])) )

#     print dp
#     return dp[m][n] 

# A Naive recursive Python program to fin minimum number
# operations to convert str1 to str2
def editDistance(str1, str2, m , n):
 
    # If first string is empty, the only option is to
    # insert all characters of second string into first
 
    # If second string is empty, the only option is to
    # remove all characters of first string
    if m==0:
    	print n
    	print "  to r"
    	print str2[n]
    	return int(str2[n])

    if n==0:
    	print m
    	print "  re   "
    	print str1[m]
        return int(str1[m])
 
    # If last characters of two strings are same, nothing
    # much to do. Ignore last characters and get count for
    # remaining strings.
    if str1[m-1] == str2[n-1]:
        return editDistance(str1,str2,m-1,n-1)
 
    return min(editDistance(str1, str2, m, n-1) + int(str2[n]),    
                   editDistance(str1, str2, m-1, n) + int(str1[m]),   
                   editDistance(str1, str2, m-1, n-1) + int(str2[n]) + int(str1[m])
                   )

print "xCccsSC"


print editDistance(str1, str2, len(str1), len(str2))
print "enf"