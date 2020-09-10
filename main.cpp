#include <bits/stdc++.h>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"

using namespace std;

int main()
{
    DNA D;
    RNA R;
    Protein P;
    CodonsTable T;
    int choice;
    cout << "Ahlan Ya User Ya Hpipy." << endl;
    cout << "What Do You want to do?" << endl << endl;
    cout << "1-Enter DNA Sequence" <<endl;
    cout << "2-Enter RNA Sequence" <<endl;
    cout << "3-Enter Protein Sequence" <<endl;
    cout << "3-Align Two Sequence" <<endl << endl;
    cout << "Enter The Choice : ";
    cin >> choice;
    /// First Choice
    if(choice == 1)
    {
        int first;
        string Seq;
        cout << "Enter Sequence : ";
        cin >> Seq;
        cout << endl;
        char* Array = new char[Seq.size()+1];
        Array[Seq.size()] = '\0';
        for(int i=0 ; i<Seq.size() ; i++) Array[i] = Seq[i];
        DNA D(Array , promoter);
        cout << "1-Convert To complementary Strand" << endl;
        cout << "2-Convert to RNA" << endl;
        cout << "3-Convert to Protein" << endl << endl;
        cout << "Enter Your Choice : ";
        cin >> first;
        if(first == 1)
        {
            D.BuildComplementaryStrand();
            D.getComp();
        }
        else if(first == 2)
        {
            D.BuildComplementaryStrand();
            D.setStart(1);
            D.setEnd(strlen(Array));
            R = D.ConvertToRNA();
            R.Print();
        }
        else if(first == 3)
        {
            D.BuildComplementaryStrand();
            D.setStart(1);
            D.setEnd(strlen(Array));
            R = D.ConvertToRNA();
            P = R.ConvertToProtein(T);
            P.Print();
        }
    }
    /// Second Choice
    else if(choice == 2)
    {
        int second;
        string Seq;
        cout << "Enter Sequence : ";
        cin >> Seq;
        cout << endl;
        char* Array = new char[Seq.size()+1];
        Array[Seq.size()] = '\0';
        for(int i=0 ; i<Seq.size() ; i++) Array[i] = Seq[i];
        RNA R(Array , mRNA);
        DNA D;
        cout << "1-Convert To DNA" << endl;
        cout << "2-Convert To Protein" << endl << endl;
        cout << "Enter Your Choice : ";
        cin >> second;
        if(second == 1)
        {
            D = R.ConvertToDNA();
            D.Print();
        }
        else if(second == 2)
        {
            P = R.ConvertToProtein(T);
            P.Print();
        }
    }
    ///Third Choice
    else if (choice == 3)
    {
        int third;
        string Seq;
        cout << "Enter Sequence : ";
        cin >> Seq;
        cout << endl;
        char* Array = new char[Seq.size()+1];
        Array[Seq.size()] = '\0';
        for(int i=0 ; i<Seq.size() ; i++) Array[i] = Seq[i];
        Protein P(Array , Hormon);
        cout << "1-Convert to DNA" << endl << endl;
        cout << "Enter Your Choice : ";
        cin >> third;
        if(third)
        {
            Protein ob;
            char BigDNA[] =
            {'A','A','A','G','A','A','G','T','T','T','G','A','A','G','T','T','T','A','A','A','A','A','G','C','C','C','C','T',
            'C','C','G','A','T','T','C','A','T','C','A','A','G','C','C','C','A','T','T','T','T','C','A','A','C','G','T','G','C',
            'A','C','\0'};
            DNA bigDNA(BigDNA , promoter);
            ob.Print(P.GetDNAStrandsEncodingMe(bigDNA));
        }
    }
    else if(choice == 4)
    {
        string Seq1 , Seq2;
        /// Take Sequence one and put it in DNA as template
        cout << "Enter Sequence 1 : ";
        cin >> Seq1;
        cout << endl;
        char* Array1 = new char[Seq1.size()+1];
        Array1[Seq1.size()] = '\0';
        for(int i=0 ; i<Seq1.size() ; i++) Array1[i] = Seq1[i];

        /// Take Sequence two and put it in DNA as template
        cout << "Enter Sequence 2 : ";
        cin >> Seq2;
        cout << endl;
        char* Array2 = new char[Seq2.size()+1];
        Array2[Seq2.size()] = '\0';
        for(int i=0 ; i<Seq2.size() ; i++) Array2[i] = Seq2[i];

        /// Save them in DNA sequence as template
        Sequence * d1 = new DNA(Array1 , promoter);
        Sequence * d2 = new DNA(Array2 , promoter);

        char* result = Align(d1 , d2);
        cout << "Common Characters : ";
        for(int i=0 ; i<strlen(result) ; i++) cout << result[i];
        cout << endl;
    }
    return 0;
}
