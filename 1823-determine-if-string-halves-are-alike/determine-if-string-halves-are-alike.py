class Solution(object):
    def halvesAreAlike(self, s):
        """
        :type s: str
        :rtype: bool
        """
        c='aeiouAEIOU'
        a=0
        b=0
        for i in range(0,len(s)):
            if(i<len(s)/2):
                if(s[i] in c):
                    a+=1 
            else:
                if(s[i] in c):
                    b+=1
        print(a,b)
        if(a==b):
            return True
        else:
            return False