#!/bin/bash
# 複数テストケースに対してスコアを計算するスクリプト
# 使い方:
#   ./score.sh          → 0000〜0049 (暫定テスト相当50ケース)
#   ./score.sh 0 9      → 0000〜0009
#   ./score.sh 0 99     → 0000〜0099

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
BINARY="$SCRIPT_DIR/a.out"
VIS="/Users/futagamitakumi/atcoder/target/release/vis"
IN_DIR="$SCRIPT_DIR/tools/in"
TMP_OUT="/tmp/ahc066_out.txt"

START=${1:-0}
END=${2:-49}

if [ ! -f "$BINARY" ]; then
    echo "ERROR: $BINARY が見つかりません。先にコンパイルしてください。"
    exit 1
fi

total=0
count=0
fail=0

for i in $(seq $START $END); do
    name=$(printf "%04d" $i)
    in_file="$IN_DIR/$name.txt"

    if [ ! -f "$in_file" ]; then
        continue
    fi

    "$BINARY" < "$in_file" > "$TMP_OUT" 2>/dev/null
    score=$("$VIS" "$in_file" "$TMP_OUT" 2>/dev/null | grep "Score" | awk '{print $NF}')

    if [ -z "$score" ]; then
        echo "[$name] ERROR"
        ((fail++))
        continue
    fi

    printf "[%s] Score = %s\n" "$name" "$score"
    total=$((total + score))
    ((count++))
done

echo "----------------------------------------"
echo "ケース数: $count  失敗: $fail"
echo "合計スコア: $total"
if [ $count -gt 0 ]; then
    avg=$((total / count))
    echo "平均スコア: $avg"
fi
