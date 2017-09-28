#!/usr/bin/python3

class Divided_Difference_Table:

    def __init__(self):
        self.flag = 0;
        self.x = []
        self.y = []
        
    def ux(self, i, u):
        if i is 0:
            return 1
        if i is 1:
            return u
        ux = u
        while i!=1:
            ux *= (u-(i-1))
            i-=1
        return ux
    
    def fact(self, i):
        if i>1:
            return i* self.fact(i-1)
        else:
            return 1

    def output(self):
        for i in range(self.s):
            if i is 0:
                print("x\ty\t", end ='')
            else:
                print("Δ{}y\t".format(i), end = '')
        print(" ")

        fx = 0
        for j in range(0,self.s):
            print("{}\t".format(self.x[j]), end='')
            for i in range(self.s-j):
                print("{:.5}\t".format(self.y[i][j]), end='')
            print()
        print("f(x):", end='')

        if self.flag is 0:
            for i in range(self.s):
                uxz = self.ux(i, self.u)
                fx += (uxz/self.fact(i))*self.y[i][0]
                if(i>0):
                    print(" + ", end='')
                print(" {:.4}".format((((uxz / self.fact(i)) * self.y[i][0]))), end='')
           
            print("\nf(x): {:.4}".format(fx))
            

    def algo(self):
        if (self.x[1]-self.x[0]) != (self.x[2]-self.x[1]):
            flag = 1
            for j in range(1,self.s):
                self.y_row = []
                for i in range(self.s-j):
                    self.ys = ((self.y[j - 1][i + 1] - self.y[j - 1][i]))/(self.x[i+j]-self.x[i])
                    self.y_row.append(self.ys)
                self.y.append(self.y_row)
            print("Unequal Interval Divided Difference Table")

        else:
            flag = 0
            self.xi = float(input("Enter interpolation of X: "))
            self.h = self.x[1] - self.x[0]
            self.u = (self.xi - self.x[0]) / self.h
            for j in range(1,self.s):
                self.y_row = []
                for i in range(self.s-j):
                    self.ys = (self.y[j - 1][i + 1] - self.y[j - 1][i])
                    self.y_row.append(self.ys)
                self.y.append(self.y_row)
            print("h: {}\nu: {:.4}\n".format(self.h, self.u))
            print()
            print("Equal Interval Divided Difference Table")

    def input(self):
        self.s = int(input("Enter Number of Element you want to insert: "))
        print("")

        for i in range(self.s):
            self.x.append(int(input("x>> ")))

        self.y_row = []
        for i in range(self.s):
            self.y_row.append(float(input("y>> ")))
        self.y. append(self.y_row)
        
        
def main():
    dft = Divided_Difference_Table()
    dft.input()
    dft.algo()
    dft.output()

if __name__ == '__main__':
    main()