// pseudocode for search operation in a trie

search(curr: Node, s: string, index: Integer):
  if(curr==NULL):
    return 0
  if(index==s.length):
    return curr.count

  nextIndex= mapping.get(s[index])

  return search(curr.next[nextIndex], s, index+1)

  
// pseudocode for delete operation in a trie:

Node delete(curr: Node, s: String, index: integer):
  s.count -= 1
  if(s.count==0):
    return NULL
  if(index== s.length):
    curr.isEnding = false
    return curr

  nextIndex= mapping.get(s[index])

  curr.next[nextIndex] = delete(curr.next[nextIndex], s, index+1)

  return curr


  
//
