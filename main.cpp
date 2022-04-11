using namespace std;
#include <iostream>
#include <vector>

#define DIMENSION 2
#define MAX_DELAY_UNIT 100000

class state_system{
public:
    double _in;
    double _out;
    vector<double> data(DIMENSION,0.0) x_d;
    vector<double> data(DIMENSION,0.0) x;
    vector<vector<double>> data(DIMENSION,data(DIMENSION,0.0)) a;
    vector<double> data(DIMENSION,0.0) b;
    vector<double> data(DIMENSION,0.0) c;
    double _t;
    vector<vector<int>> data(DIMENSION,data(DIMENSION,1)) flag_a;
    vector<int> data(DIMENSION,1) flag_b;
    vector<int> data(DIMENSION,1) flag_c;
    double dev_min;
    vector<double> data(MAX_DELAY_UNIT,0.0) mudajikan_array;
    int array_write_position;
    int array_read_position;
    int delay_num;
    int dimension_size = DIMENSION;
    int elem_base = 300;
    int flag;

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


}

int main(int argc, char **argv){
    cout << "hello" << endl;
    return 0;    
}