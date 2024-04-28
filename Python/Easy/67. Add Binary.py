# https://leetcode.com/problems/add-binary/description/

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        la=list(a)
        lb=list(b)
        if len(la)<len(lb):
            la=['0']*(len(lb)-len(la)+1)+la
            lb=['0']+lb
        else:
            lb=['0']*(len(la)-len(lb)+1)+lb
            la=['0']+la
        s=[]
        rest=0
        for i in range(len(la)-1,-1,-1):
            tmp=int(la[i])+int(lb[i])+rest
            if tmp==0:
                s.append('0')
                rest=0
            elif tmp==1:
                s.append('1')
                rest=0
            elif tmp==2:
                s.append('0')
                rest=1
            elif tmp==3:
                s.append('1')
                rest=1
        result = ''.join(s[::-1])
        if result[0]=='0':
            return result[1:]
        return result