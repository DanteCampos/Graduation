from docplex.mp.model import Model
import cplex

m = Model(name='Incendio')

x_1 = m.integer_var(name='x_1')
x_2 = m.integer_var(name='x_2')
x_3 = m.integer_var(name='x_3')

m.add_constraint(15*x_1 + 40*x_2 + 85*x_3 >= 600)
m.add_constraint(2*x_1 <= 10)
m.add_constraint(2*x_2 + 2*x_3 <= 14)
m.add_constraint(x_2 + 3*x_3 <= 22)

m.add_constraint(x_1>=0)
m.add_constraint(x_2>=0)
m.add_constraint(x_3>=0)


m.minimize(2000*x_1 + 4000*x_2 + 10000*x_3)
m.solve()
print(m.solution)
#m.export_as_lp("a.lp")
