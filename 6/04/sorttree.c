void sorttree(struct word *root) {


}

struct word *rightrot(struct word *root) {
    struct word *p = NULL;

    if(root->left == NULL) {
        printf("NOTICE: max rr of tree");
        return;
    } else if(root->left->right == NULL) {
        *p = root->left;
        root->right = root;
        root->left = NULL;
    }

    return p;
}
