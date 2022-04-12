using namespace std;
#include <iostream>
#include <vector>

const int DIMENSION = 2;
const int MAX_DELAY_UNIT = 100000;

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
    int dimension_size = DIMENSION;
    int elem_base = 300;
    int flag;


    state_system(){
        x_d.resize(DIMENSION);
        x.resize(DIMENSION);
        a.resize(DIMENSION);
        for(size_t i = 0; i < DIMENSION;i++){
            a[i].resize(DIMENSION);
        }
        b.resize(DIMENSION);
        c.resize(DIMENSION);
    }

    void delay_array_init(int delay_num){
        this->delay_num = delay_num;
        this->array_read_position = 0;
        this->array_write_position = this->delay_num;
    }
    void system_init(void){
        int i;
        this->_in = 0.0;
        this->_out = 0.0;
        for(i = 0;i < DIMENSION; i++){
            this->x_d[i] = 0.0;
        }

        for(i = 0;i < DIMENSION; i++){
            this->x[i] = 0.0;
        }
    }
    void system(){
        int i;
        int j;

        for(i = 0;i < DIMENSION;i++){
            this->x_d[i]=0.0;
            for(j = 0;j < DIMENSION;j++){
                this->x_d[i] += this->x[j] * this->a[i][j];
            }
            this->x_d[i] += this->_in * this->b[i];
        }
        for(i = 0;i < DIMENSION;i++){
            this->x[i] += this->x_d[i] * this->_t;
        }

        
    }


};

int main(int argc, char **argv){
    state_system solver;
    cout << "hello" << endl;
    return 0;    
}