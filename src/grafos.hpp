#pragma once

#include <vector>
#include <unordered_map>

class Grafo{
  private:
    std::vector<std::vector<std::pair<int, int>>> adjacencias;
    std::unordered_map<int, std::unordered_map<int, int>> custos;
  public:
    Grafo(int num_vertices){
      adjacencias.resize(num_vertices);
    };

    void adicionarAresta(int u, int v, int custo) {
      adjacencias[u].push_back({v, custo});
      custos[u][v] = custo;
    };

    int obterCustoAresta(int u, int v) const {
      return custos.at(u).at(v);
    };
    int obterNumVertices() const{
      return adjacencias.size();
    };

    const std::vector<std::pair<int, int>>& obterAdjacencias(int v) const{
      return adjacencias.at(v);
    };
};

class Pedido{
  private:
    int ponto_coleta;
    int ponto_entrega;
    int demanda;
    int tempo_servico;
    int janela_inicio;
    int janela_fim;
  public:
    Pedido(int i, int j, int demanda, int tempo_servico, int janela_inicio, int janela_fim){
      this->ponto_coleta = i;
      this->ponto_entrega = j;
      this->demanda = demanda;
      this->tempo_servico = tempo_servico;
      this->janela_inicio = janela_inicio;
      this->janela_fim = janela_fim;
    };

    int obterPontoColeta() const{
      return this->ponto_coleta;
    }
    
    int obterPontoEntrega() const{
      return this->ponto_coleta;
    }
    
    int obterDemanda() const{
      return this->demanda;
    }
    int obterTempoServico() const{
      return this->tempo_servico;
    }
    int obterJanelaInicio() const{
      return this->janela_inicio;
    }
    int obterJanelaFim() const{
      return this->janela_fim;
    }
};

class Veiculo{
  private:
    int capacidade;
    int tempo_inicio;
    int tempo_fim;
  public:
    Veiculo(int capacidade, int tempo_inicio, int tempo_fim){
      this->capacidade = capacidade;
      this->tempo_inicio = tempo_inicio;
      this->tempo_fim = tempo_fim;
    }

    int obterCapacidade() const{
      return this->capacidade;  
    };
    int obterTempoInicio() const{
      return this->tempo_inicio;
    }

    int obterTempoFim() const{
      return this->tempo_fim;
    };
};

class Rota{
  private:
    int veiculo;
    std::vector<Pedido> pedidos;
    int carga_atual;
  public:
    Rota(int veiculo){
      this->veiculo = veiculo;
      this->carga_atual = 0;
    };

    void adicionarPedido(const Pedido& pedido){
      pedidos.push_back(pedido);
      carga_atual += pedido.obterDemanda();
    };
    
    int obterVeiculo() const{
      return veiculo;
    };

    int obterCustoTotal(const Grafo& grafo) const{
      int custo  = 0;
      int numero_pedidos = pedidos.size();
      
      if (numero_pedidos == 0){
        return custo;  
      }
      
      int origem = veiculo;
      int destino = pedidos.front().obterPontoColeta();
      custo += grafo.obterCustoAresta(origem, destino);
      origem = destino;

      for(int i = 0; i < numero_pedidos; ++i){
        destino = pedidos[i].obterPontoColeta();
        custo += grafo.obterCustoAresta(origem, destino);
        origem = destino;

        destino = pedidos[i].obterPontoEntrega();
        custo += grafo.obterCustoAresta(origem, destino);
        origem = destino;
      }
      
      destino = veiculo;
      custo += grafo.obterCustoAresta(origem, destino);
      return custo;
    }

    int obterCargaAtual() const{
      return carga_atual;
    };
};

class Solucao{
  private:
    std::vector<Rota> rotas;
  public:
    Solucao(const std::vector<Veiculo>& veiculos){
      for (int i = 0; i < veiculos.size(); ++i){
        rotas.emplace_back(i);
      }
    };
    
    void adicionarRota(const Rota& rota){
      rotas.push_back(rota);
    };
    
    int obterNumRotas() const{
      return rotas.size();
    };
    const Rota& obterRota(int indice) const{
      return rotas[indice];
    };
    
    int obterCustoTotal(const Grafo& grafo) const{
      int custo_total = 0;
      for (const auto& rota : rotas){
        custo_total += rota.obterCustoTotal(grafo);
      }
      return custo_total;
    };
};
