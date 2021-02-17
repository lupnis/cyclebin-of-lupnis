#ifndef CACENC_H
#define CACENC_H

class CACEnc{
    public:
        CACENC(int mapsize, map<int,bool> ikeypairs,int maxdepth){
            graph=new (**int)malloc(sizeof(int*mapsize));
            keypairs=ikeypairs;
            maxsteps=maxdepth;
        }
        ~CACEnc(){}
        void input(string stream);
        void calcNext();
        void clac(int times);
        std::string getString(); 
    private:
        bool graph[][];
        int maxsteps;
        map<int,bool> keypairs;
        void visualize();
        void textualize();
}

#endif // !CACENC_H
