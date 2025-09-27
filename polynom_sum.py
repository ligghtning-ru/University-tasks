import time


def func_decorator(func):
    def wrapper(p1, p2):
        st = time.time()
        res = func(p1, p2)
        et = time.time()
        print(f'Код выполнился за (первоначальное время умножено на 10^2 для удобства): {(et - st)*10**2}*10^-2 с')
        return res

    return wrapper


@func_decorator
def polynomial_sum(p1, p2):
    i = 0
    j = 0

    t = []
    len_p1 = len(p1)
    len_p2 = len(p2)
    ost = []

    if len_p1 >= len_p2:
        difference_s = len_p1 - len_p2
        i = difference_s
        ost = p1[:i]
    else:
        difference_s = len_p2 - len_p1
        j = difference_s
        ost = p2[:j]

    while True:
        if i < len_p1 and j < len_p2:
            t.append(p1[i] + p2[j])
            i += 1
            j += 1
        else:
            break

    for i, el in enumerate(ost):
        t.insert(i, el)

    len_t = len(t)
    ost = []

    for i in range(len_t):
        checking = t[i]
        pw = f'^{len_t - i - 1}'
        sign = '- ' if checking < 0 else '+ '

        if checking == 0:
            continue

        if pw == '^1':
            pw = ''

        if i == len_t - 1:
            el = checking
            ost.append(checking)
            break

        if checking in (-1, 1):
            if i != 0:
                el = f' - x{pw} ' if checking == -1 else f' + x{pw} '
            else:
                el = f' -x{pw} ' if checking == -1 else f' + x{pw} '
            ost.append(el)
            continue

        el = f' {sign}{abs(t[i])}x{pw} '

        ost.append(el)

    if len(ost) == 0:
        return 0

    last = ost[-1]
    if isinstance(last, int):
        sign = '- ' if last < 0 else '+ '
        ost[-1] = f'{sign}{abs(last)}'

    res = ''.join(ost).strip(' +')

    while res.count('  ') != 0:
        res = res.replace('  ', ' ')

    return res
