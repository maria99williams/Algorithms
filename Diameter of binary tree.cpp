// Approach1
// Since (diameter = 1 + leftHeight + rightHeight) for every node
int ans = -1;
int diameter(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftHeight = diameter(root->left);
	int rightHeight = diameter(root->right);
	ans = max(ans , 1 + leftHeight + ightHeight);
	return 1 + max(leftHeight , rightHeight);
}