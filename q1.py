A=['a','b','c','d']
def next(s):
    for i in range(len(s)-1,-1,-1):
        if s.count('d') == len(s):
            return 'a'*(len(s)+1)
        if s[i] == A[-1]:
            pass
        elif s[i] in A:
            for n in range(len(A)):
                if A[n] == s[i]:
                    s=s[0:i]+A[n+1]+'a'*len(s[i+1:])
                    break
            break
    return s
#ý 1.1
test=['aca','bccc','ddd','bbcd','ddabdc','addd','a','b']
test1=['acb','aaa','dad','aab']
for i in test:
    print(f'chuoi tiep theo la : {next(i)}')
##y 1.2    
def closest_wavy(s):
    for i in range(len(s)-1, -1, -1):
        if s[i] in A:
            for n in range(len(A)):
                if A[n] == s[i]:
                    for m in range(n + 1, len(A)):
                        new_char = A[m]
                        temp_s = s[0:i] + new_char
                        is_wavy = True
                        for j in range(len(temp_s) - 1):
                            if j % 2 == 0 and not (temp_s[j] < temp_s[j+1]):
                                is_wavy = False
                                break
                            elif j % 2 == 1 and not (temp_s[j] > temp_s[j+1]):
                                is_wavy = False
                                break
                        
                        if is_wavy == True:
                        
                            dead_end = False
                            if len(temp_s) < len(s):
                                if (len(temp_s) - 1) % 2 == 0 and new_char == 'd':
                                    dead_end = True
                                elif (len(temp_s) - 1) % 2 == 1 and new_char == 'a':
                                    dead_end = True
                            
                            if dead_end == False:
                                ans = temp_s
                                while len(ans) < len(s):
                                    if (len(ans) - 1) % 2 == 0:
                                        for k in range(len(A)):
                                            if A[k] == ans[-1]:
                                                ans = ans + A[k+1]
                                                break
                            
                                    elif (len(ans) - 1) % 2 == 1:
                                        ans = ans + 'a'
                                return ans
    ans = ''
    for i in range(len(s) + 1):
        if i % 2 == 0:
            ans = ans + 'a'
        else:
            ans = ans + 'b'
    return ans
for i in test1:
    print(f'chuoi song gan nhat dung sau S la :{closest_wavy(i)}') 