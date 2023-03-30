def dz_hrf(s, prefix=""):
    count = 0
    if len(s) == 0:
        if prefix:
            count += 1
        return count

    if s[0] not in "aeiou":
        count += dz_hrf(s[1:], prefix + s[0])


    count += dz_hrf(s[1:], prefix)

    return count

s = input()
count = dz_hrf(s)

print(count)