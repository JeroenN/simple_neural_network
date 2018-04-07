#include <iostream>
#include <vector>

class neuron{};
typedef std::vector<neuron> layer;

class net
{
public:
    net(const std::vector<unsigned> &topology);
    void feed_forward(const std::vector<double> &input_values) {};
    void back_propagation(const std::vector<double> &target_values) {};
    void get_results(std::vector<double> &result_values) const {};
private:
    std::vector<layer> m_layers; //m_layers[layer_number][neuron_number]
};

net::net(const std::vector<unsigned> &topology)
{
    //creating rows and columns -> layers and neurons
    unsigned n_layers = topology.size();
    for(unsigned layer_number=0; layer_number!=n_layers; ++ layer_number)
    {
        m_layers.push_back(layer());
        //using <= for the bias layer
        for(unsigned neuron_number=0; neuron_number<= topology[layer_number]; ++neuron_number)
        {
            m_layers.back().push_back(neuron());
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
