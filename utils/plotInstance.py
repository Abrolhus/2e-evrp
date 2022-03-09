import numpy as np
print("hello");
import matplotlib.pyplot as plt
import sys

table = np.loadtxt(sys.argv[1])
print(table)

nTrucks = table[0][0].astype(int)
nEvs = table[0][1].astype(int)
nDepots = table[0][2].astype(int)
nSats = table[0][3].astype(int)
nRss = table[0][4].astype(int)
nCusts = table[0][5].astype(int)
print(nTrucks, nEvs, nDepots, nSats, nRss, nCusts)

plt.figure()
plt.legend(prop={'size': 6})
plt.legend()
plt.xlabel("x")
plt.ylabel("y")
# these are matplotlib.patch.Patch properties
fig, ax = plt.subplots()
props = dict(boxstyle='round', facecolor='wheat', alpha=0.5)
plt.grid(visible=True)

# place a text box in upper left in axes coords

readLine = 1;
for i in range(readLine, readLine + nTrucks):
    truckCap = table[i][0]
    print("capacity", truckCap)
    readLine += 1;
print("Evs: ")
for i in range(readLine, readLine + nEvs):
    evCap = table[i][0]
    print("capacity", evCap)
    readLine += 1;

print("depot: ")
for i in range(readLine, readLine + nDepots):
    print("depot", table[i][0], table[i][1], table[i][2])
    plt.scatter(float(table[i][0]), float(table[i][1]), color='r', s=100, marker='s', alpha=0.8, zorder=1)
    readLine += 1;
print("Satelites: ")
for i in range(readLine, readLine + nSats):
    print("sat", table[i][0], table[i][1], table[i][2])
    plt.scatter(float(table[i][0]), float(table[i][1]), color='g', s=100, marker='d', alpha=0.8, zorder=10)
    readLine += 1;
print("RSs: ")
for i in range(readLine, readLine + nRss):
    print("rs", table[i][0], table[i][1], table[i][2])
    plt.scatter(float(table[i][0]), float(table[i][1]), color='b', s=100, marker='^', alpha=0.8, zorder=5)
    readLine += 1;
print("Custumers: ")
for i in range(readLine, readLine + nCusts):
    print("cust", table[i][0], table[i][1], table[i][2])
    plt.scatter(float(table[i][0]), float(table[i][1]), color='black', s=100, marker='o', alpha=0.8, zorder=1)
    #plt.annotate(table[i][2],(table[i][0],table[i][1]), color='r')
    #plt.annotate(table[i][5],(table[i][0],table[i][1]-5), color='black')
    #plt.annotate(table[i][6],(table[i][0],table[i][1]-10), color='black')
    text = str(int(table[i][2])) + "\n" + str(int(table[i][5])) + ", " +str(int(table[i][6]))
    ax.text(table[i][0], table[i][1]-5, text, fontsize=8,
            verticalalignment='top', bbox=props)
    readLine += 1;
ax.set_title(str(nTrucks) + ' trucks'+ "(cap: " + str(truckCap) + ")"', '+ str(nEvs) + ' evs' + "(cap: " + str(evCap) + ")" + '\n')
ax.annotate('Footnote added below the chart with a smaller font',
            xy = (1.0, -0.2),
            ha='right',
            va="center",
            fontsize=14)
plt.savefig('test' + 'vai'+ '.png')
