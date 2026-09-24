/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Codec {
    public void dfsser(TreeNode root,List<String> str){
        if(root == null)
        {
            str.add("N");
            return;
        }
        str.add(String.valueOf(root.val));
        dfsser(root.left,str);
        dfsser(root.right,str);
    }
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        List<String> str = new ArrayList<>();
        dfsser(root,str);
        return String.join(",",str);
    }
    public TreeNode dfsder(String[] vals,int[] i){
        if(vals[i[0]].equals("N")){
            i[0]++;
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(vals[i[0]]));
        i[0]++;
        node.left = dfsder(vals,i);
        node.right = dfsder(vals, i);
        return node;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] val = data.split(",");
        int[] i = {0};
        return dfsder(val,i);
        
    }
}
