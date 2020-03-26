N = 27

def create_words(line_no, N):
    words = '' #create increasing sequence
    for num in range(0, line_no):
        words = words + '-' + chr(ord('a')-1+N-num)
    
    # sequence + middle + reverse sequence
    mid =  chr(ord('a')-1+N-line_no)
    words = words + '-' + mid + '-' + words[::-1]
    words = words[1:-1] # too much dash
    return words

# top triangle
for k in range(0, N):
    dashes = 2*(N-k-1) * '-'
    line =  dashes + create_words(k,N) + dashes
    print(line)

# upside down triangle
for k in range(N-2, -1, -1):
    dashes = 2*(N-k-1) * '-'
    line = dashes + create_words(k,N) + dashes
    print(line)
