def egyptian_fraction(nr, dr):
    ef = []
    while nr != 0:
        x = (dr + (nr-1)) // nr
        ef.append(x)
        nr = x * nr - dr
        dr = dr * x
    for i in range(len(ef)):
        print("1/%d" % ef[i], end = '')
        if i < len(ef) - 1:
            print(' + ', end='')

nr, dr = 6, 14
print("The Egyptian Fraction Representation of %d/%d is" % (nr, dr))
egyptian_fraction(nr, dr)
