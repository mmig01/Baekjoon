#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
void storeCount(const string &, int[]);
int getPercent(int[]);
int main()
{
    string sYonduName, sTempName;
    string sMaxName;
    int iLOVEcount[4];
    int i, j, iCount, iIndex;
    int iWinPercent, iMaxPercent;
    sMaxName = " ";
    cin >> sYonduName;
    cin >> iCount;
    iWinPercent = 0;
    iMaxPercent = 0;
    for (i = 0; i < iCount; i++)
    {
        for (j = 0; j < 4; j++)
        {
            iLOVEcount[j] = 0 ;
        }

        cin >> sTempName;
        storeCount(sYonduName, iLOVEcount);
        storeCount(sTempName, iLOVEcount);
        iWinPercent = getPercent(iLOVEcount);

        if (sMaxName == " ")
        {
            iMaxPercent = iWinPercent;
            sMaxName = sTempName;
        }
        else
        {
            if (iWinPercent > iMaxPercent)
            {
                iMaxPercent = iWinPercent;
                sMaxName = sTempName;
            }
            else if (iWinPercent == iMaxPercent)
            {
                if (sTempName.compare(sMaxName) < 0)
                {
                    iMaxPercent = iWinPercent;
                    sMaxName = sTempName;
                }
            }
        }
    }
    cout << sMaxName;
    return 0;
}

void storeCount(const string & name, int iLOVEcount[])
{
    int i;
    for (i = 0; i < name.length(); i++)
    {
        if (name[i] == 'L')
            iLOVEcount[0]++ ;
        else if (name[i] == 'O')
            iLOVEcount[1]++;
        else if (name[i] == 'V')
            iLOVEcount[2]++;
        else if (name[i] == 'E')
            iLOVEcount[3]++;
    }
}
int getPercent(int iLOVEcount[])
{
    int i;
    i = (iLOVEcount[0] + iLOVEcount[1]) * (iLOVEcount[0] + iLOVEcount[2]) * (iLOVEcount[0] + iLOVEcount[3]) * (iLOVEcount[1] + iLOVEcount[2]) * (iLOVEcount[1] + iLOVEcount[3]) * (iLOVEcount[2] + iLOVEcount[3]) % 100 ;
    return i;
}