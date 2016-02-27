# UVA ya acepta Python3 

def primes_upto(limit):
    is_prime = [False] + [True] * limit 
    for n in range(2, int(limit**0.5 + 1.5)): # stop at ``sqrt(limit)``
        if is_prime[n]:
            for i in range(n*n, limit+1, n):
                is_prime[i] = False
    return is_prime

def main():
    try:
        is_prime = primes_upto(1000000)
        while True:
            s = input()
            a, b = int(s), int(s[::-1])
            if not is_prime[a]:
                print("{} is not prime.".format(s))
            elif (is_prime[a] and a == b) or not (is_prime[a] and is_prime[b]):
                print("{} is prime.".format(s))
            else:
                print("{} is emirp.".format(s))
    except:
        pass
    
main()
