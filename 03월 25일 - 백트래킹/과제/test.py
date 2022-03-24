l, c = map(int, input().split())
dic = list(input().split())

dic.sort()

answer = []

vowel = ['a', 'e', 'i', 'o', 'u']
 
cur_word = [''] * l


def password(idx, con, vow, length):
    if length == l and con >= 2 and vow >= 1:
        print(''.join(cur_word))
        return

    if length > l or idx >= c:
        return

    

    cur_word[length] = dic[idx]
    length += 1


    if cur_word[length-1] in vowel:
        password(idx+1, con, vow+1, length)
    else:
        password(idx+1, con+1, vow, length)

    length -= 1
    password(idx+1, con, vow, length)


password(0, 0, 0, 0)