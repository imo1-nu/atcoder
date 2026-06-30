# テストケースの数を自動検出
n=0
for file in *.in; do
    if [[ -f "$file" ]]; then
        num=$(echo "$file" | sed 's/\.in$//')
        if [[ "$num" =~ ^[0-9]+$ ]] && [[ $num -gt $n ]]; then
            n=$num
        fi
    fi
done

echo "検出されたテストケース数: $n"

# 各テストケースを実行して比較
for i in $(seq 1 $n); do
    input_file="${i}.in"
    expected_file=""
    
    # .out または .ans ファイルを探す
    if [[ -f "${i}.out" ]]; then
        expected_file="${i}.out"
    elif [[ -f "${i}.ans" ]]; then
        expected_file="${i}.ans"
    else
        echo "テストケース $i: 期待される出力ファイル (${i}.out または ${i}.ans) が見つかりません"
        continue
    fi
    
    if [[ ! -f "$input_file" ]]; then
        echo "テストケース $i: 入力ファイル $input_file が見つかりません"
        continue
    fi
    
    echo "=== テストケース $i ==="
    
    # プログラムを実行
    actual_output=$(python main.py < "$input_file")
    expected_output=$(cat "$expected_file")
    
    # 出力を比較
    if [[ "$actual_output" == "$expected_output" ]]; then
        echo "✅ PASS"
    else
        echo "❌ FAIL"
        echo "期待される出力:"
        echo "$expected_output"
        echo "実際の出力:"
        echo "$actual_output"
    fi
    echo ""
done