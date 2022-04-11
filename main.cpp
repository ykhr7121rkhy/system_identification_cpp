using namespace std;
#include "iostream"

class state_system{
public:
    double _in;
    double _out;
    vector<double> x_d;
    vector<double> x;
    vector<vector<double>> a;
    vector<double> b;
    vector<double> c;
    double _t;
    vector<vector<int>> flag_a;
    vector<int> flag_b;
    vector<int> flag_c;
    double dev_min;
    vector<double> mudajikan_array;
    int array_write_position;
    int array_read_position;
    int delay_num;
    int dimension_size;
    int elem_base;
    int flag;
}

int main(int argc, char **argv){
    cout << "hello" << endl;
    return 0;    
}