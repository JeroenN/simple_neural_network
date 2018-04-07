#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

struct connection
{
  double weight;
  double delta_weight;
};

class neuron;
typedef std::vector<neuron> layer;
//********************************** Class neuron **************************

class neuron
{
public:
    neuron(unsigned n_outputs);
private:
    static double random_weight(void)
    {
        return rand() / double(RAND_MAX); //Maybe this function will get bigger, otherwise remove function and write in line.
    }
    double m_output_value;
    std::vector<connection> m_output_weights;

};

neuron::neuron(unsigned n_outputs)
{
    for(unsigned c=0; c< n_outputs; ++c)
    {
        m_output_weights.push_back(connection());
        m_output_weights.back().weight = random_weight();
    }
}
//********************************** Class net **************************

class net
{
public:
    net(const std::vector<unsigned> &topology);
    void feed_forward(const std::vector<double> &input_values) ;
    void back_propagation(const std::vector<double> &target_values) {};
    void get_results(std::vector<double> &result_values) const {};
private:
    std::vector<layer> m_layers; //m_layers[layer_number][neuron_number]
};

void net::feed_forward(const std::vector<double> &input_values)
{
    assert(input_values.size() == m_layers[0].size() );
}
net::net(const std::vector<unsigned> &topology)
{
    //creating rows and columns -> layers and neurons
    unsigned n_layers = topology.size();
    for(unsigned layer_number=0; layer_number<n_layers; ++layer_number)
    {
        m_layers.push_back(layer());
        unsigned n_outputs;
        if(layer_number==topology.size() - 1)
        {
            n_outputs =  0;
        }
        else
        {
            n_outputs =topology[layer_number +1];
        }
        //using <= for the bias layer
        for(unsigned neuron_number=0; neuron_number<= topology[layer_number]; ++neuron_number)
        {
            m_layers.back().push_back(neuron(n_outputs));
            std::cout<< "Neuron created!" << "\n";
        }

    }
}
int main()
{
    std::vector<unsigned> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(1);
    net my_net(topology);
    std::vector<double> input_values;
    my_net.feed_forward(input_values);

    std::vector<double> target_values;
    my_net.back_propagation(target_values);

    std::vector<double> result_values;
    my_net.get_results(result_values);
}
