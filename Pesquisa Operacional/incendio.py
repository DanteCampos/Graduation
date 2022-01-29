from docplex.mp.model import Model
import cplex

# Inicializando variáveis

m1 = Model(name='Incendio-Custo')
m2 = Model(name='Incendio-Area')

x = dict()
y = dict()

for i in range(1,4):
    x[i] = m1.integer_var(name='x_{0}'.format(i))

for i in range(1,4):
    y[i] = m2.integer_var(name='x_{0}'.format(i))



# Problema original
# A região viável desse problema é vazia

m1.add_constraint(45000*x[1] + 120000*x[2] + 255000*x[3] >= 3000000) # Apagar os 3*10^6 de m^2
m1.add_constraint(2*x[1] <= 10) # Pilotos de helicóptero
m1.add_constraint(2*x[2] + 2*x[3] <= 14) # Pilotos de avião
m1.add_constraint(x[2] + 3*x[3] <= 22) # Operadores

for i in range(1,4):
    m1.add_constraint(x[i]>=0)

m1.minimize(6000*x[1] + 12000*x[2] + 30000*x[3])
m1.solve()


# Problema alterado para maximizar área desconsiderando o custo

m2.add_constraint(2*y[1] <= 10) # Pilotos de helicóptero
m2.add_constraint(2*y[2] + 2*y[3] <= 14) # Pilotos de avião
m2.add_constraint(y[2] + 3*y[3] <= 22) # Operadores

for i in range(1,4):
    m2.add_constraint(y[i]>=0)

m2.maximize(45000*y[1] + 120000*y[2] + 255000*y[3]) # Área apagada
m2.solve()

# Printando resultados

print ("Solução do problema original:")
print(m1.solution)

print ("Solução do problema alterado:")
print(m2.solution)

#m1.export_as_lp("incendio_custo.lp")
#m2.export_as_lp("incendio_area.lp")

