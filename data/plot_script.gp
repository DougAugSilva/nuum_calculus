set terminal pngcairo size 600,400
set output 'data/grafico.png'
set title 'Gráfico da função y = x^2'
set xlabel 'Eixo X'
set ylabel 'Eixo Y'
plot 'data/dados.txt' with linespoints title 'Parábola'
