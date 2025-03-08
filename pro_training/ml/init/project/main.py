def main():
    str = "hello world"
    len_str = len(str)
    i = 0
    while i < len_str:
        print(str[i], end="")
        i += 1
    print()
    return str, len_str


if __name__ == "__main__":
    str, len = main()
    if str is not None:
        print(str ,"de taille", len)