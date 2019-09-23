# Tarjan Algorithm with Directed Graph

## SCCS
Strongly connected components is self-contained cycles within a directed graph where every vertex in a given cycle can reach every other vertex in the same cycle. 


```mermaid
graph BT
a1-->b1
a3-->b1
c1-->a1
c1-->b2
subgraph 
a1((a1))-->a2((a2))
a1-->a3((a3))
a2-->a1
a2-->a3
a3-->a2
a3-->a1
end
subgraph 
b1((b1))-->b2((b2))
b2-->b1
end
subgraph 
c1((c1))-->c2((c2))
c1-->c3((c3))
c2-->c1
c2-->c3
c3-->c2
c3-->c1
end
subgraph 
d1-->d1((d1))
end

```

# Synchronization
There are two types of synchronization and they can complement each other:

- The workspace synchronization will sync all your files, folders and settings automatically. This will allow you to fetch your workspace on any other device.
	> To start syncing your workspace, just sign in with Google in the menu.

- The file synchronization will keep one file of the workspace synced with one or multiple files in **Google Drive**, **Dropbox** or **GitHub**.
	> Before starting to sync files, you must link an account in the **Synchronize** sub-menu.




<!--stackedit_data:
eyJoaXN0b3J5IjpbLTIyOTQxNDEzOCwtMTQ3NjM3ODg1MV19
-->