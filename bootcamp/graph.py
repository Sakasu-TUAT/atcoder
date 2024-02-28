import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
import networkx as nx

class GraphDrawerApp:
    def __init__(self, master):
        self.master = master
        self.master.title("Graph Drawer")

        # チェックボックスの変数
        self.chk_1_indexed = tk.BooleanVar()
        self.chk_directed = tk.BooleanVar()
        self.chk_weighted = tk.BooleanVar()
        self.chk_smooth = tk.BooleanVar()
        self.chk_normal = tk.BooleanVar()

        # チェックボックスを作成
        chk_1_indexed_checkbox = ttk.Checkbutton(master, text="1-indexed", variable=self.chk_1_indexed, command=self.on_checkbox_change)
        chk_directed_checkbox = ttk.Checkbutton(master, text="Directed", variable=self.chk_directed, command=self.on_checkbox_change)
        chk_weighted_checkbox = ttk.Checkbutton(master, text="Weighted", variable=self.chk_weighted, command=self.on_checkbox_change)
        chk_smooth_checkbox = ttk.Checkbutton(master, text="Smooth", variable=self.chk_smooth, command=self.on_checkbox_change)
        chk_normal_checkbox = ttk.Checkbutton(master, text="Normal Layout", variable=self.chk_normal, command=self.on_checkbox_change)

        # 描画ボタン
        btn_draw = ttk.Button(master, text="Draw Graph", command=self.on_draw_button_click)

        # レイアウトを設定
        chk_1_indexed_checkbox.grid(row=0, column=0, sticky="w")
        chk_directed_checkbox.grid(row=1, column=0, sticky="w")
        chk_weighted_checkbox.grid(row=2, column=0, sticky="w")
        chk_smooth_checkbox.grid(row=3, column=0, sticky="w")
        chk_normal_checkbox.grid(row=4, column=0, sticky="w")
        btn_draw.grid(row=5, column=0, pady=10)

        # FigureCanvasTkAggを作成
        self.fig, self.ax = plt.subplots()
        self.canvas = FigureCanvasTkAgg(self.fig, master=master)
        self.canvas.get_tk_widget().grid(row=0, column=1, rowspan=6)

        # 初回描画
        self.on_checkbox_change()
        self.on_draw_button_click()

        # ウィンドウが閉じられたときのイベントハンドラを設定
        self.master.protocol("WM_DELETE_WINDOW", self.on_closing)

    def draw_graph(self):
        # 以前のグラフを削除
        self.ax.clear()
        self.fig.clear()

        # グラフの描画
        pos = nx.spring_layout(self.G) if self.chk_normal.get() else nx.shell_layout(self.G)
        nx.draw(self.G, pos, with_labels=True, node_size=500, node_color='skyblue', font_size=8, font_color='black', font_weight='bold', edge_color='gray', linewidths=0.5)

        if self.chk_directed.get():
            self.ax.set_title("Directed Graph")
        else:
            self.ax.set_title("Undirected Graph")

        # 描画結果を更新
        self.canvas.draw()

    def on_checkbox_change(self, *args):
        # チェックボックスが変更されたら都度描画
        self.on_draw_button_click()

    def on_draw_button_click(self):
        try:
            offset = 1 if self.chk_1_indexed.get() else 0
            directed = self.chk_directed.get()
            weighted = self.chk_weighted.get()
            smooth = self.chk_smooth.get()
            normal = self.chk_normal.get()

            # グラフの辺を読み込む
            edges = []
            with open("in.txt", 'r') as file:
                N = int(file.readline().strip())
                for _ in range(N - 1):
                    u, v = map(int, file.readline().split())
                    edges.append((u - offset, v - offset))

            # networkxのグラフを作成
            self.G = nx.Graph()
            self.G.add_edges_from(edges)

            if weighted:
                # 重みつきグラフの場合、重みを付加
                for edge in self.G.edges():
                    self.G.edges[edge]['weight'] = 1.0  # 仮の重みを設定

            # グラフを描画
            self.draw_graph()
        except Exception as e:
            messagebox.showerror("Error", str(e))

    def on_closing(self):
        # ウィンドウが閉じられるときの処理
        self.master.quit()

if __name__ == "__main__":
    root = tk.Tk()
    app = GraphDrawerApp(root)
    root.mainloop()
