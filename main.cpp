using namespace std;
#include <iostream>
#include <vector>


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
    int dimension_size = 2;
    int elem_base = 300;
    int flag;

    void state_system(){
        this->a = {{0.0,0.0},{0.0,0.0}};
        this->b = {{0.0,0.0}};
        this->c = {{0.0,0.0}};
    }
    void delay_array_init(int delay_num){
        this->delay_num = delay_num;
        this->array_read_position = 0;
        this->array_write_position = this->delay_num;
    }


}

int main(int argc, char **argv){
    cout << "hello" << endl;
    return 0;    
}