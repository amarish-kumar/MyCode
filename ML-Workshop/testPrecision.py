from sklearn.metrics import classification

y_t = [0, 1, 2, 1, 0]
y_p = [0, 0, 2, 0, 1]
t_name = ['A', 'B', 'C']
print(classification.classification_report(y_t, y_p, target_names=t_name))
