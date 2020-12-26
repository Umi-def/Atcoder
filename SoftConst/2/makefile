CC =gcc #変数を宣言
OBJS =array.o sort.o max_min.o 12-2.o #すべてのオブジェクトファイル

12-2: $(OBJS) #依存関係のファイルが変わったら実行ファイルを作りなおす
	$(CC) -o $@ $^ 
#依存関係のあるファイルをリンクして実行ファイルを作成
#$@:ターゲットファイル名(12-2) $^:全ての依存するファイル名（OBJS)

.c.o: #.oがなければ.cから作成する
	$(CC) -c $<
#$<:最初に依存するファイル

12-2.o: array.h sort.h max_min.h #依存関係の指定
max_min.o: array.h sort.h max_min.h
sort.o: sort.h
array.o: array.h

.PHONY: clean #cleanというファイルが存在してもcleanを実行
clean:
	rm -f 12-2 $(OBJS)
#いつでも作れるファイルは削除（実行ファイル、オブジェクトファイル）