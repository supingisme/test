#include <utils.h>
#include "virtio_client.h"

struct vring_used_elem *virt_queue__set_used_elem(struct vring_virtqueue *vq, u32 head, u32 len)
{
	struct vring_used_elem *used_elem;

	used_elem	= &vq->vring.used->ring[vq->vring.used->idx % vq->vring.num];
	used_elem->id	= head;
	used_elem->len	= len;

	/*
	 * Use wmb to assure that used elem was updated with head and len.
	 * We need a wmb here since we can't advance idx unless we're ready
	 * to pass the used element to the guest.
	 */
	mb();
	vq->vring.used->idx++;

	/*
	 * Use wmb to assure used idx has been increased before we signal the guest.
	 * Without a wmb here the guest may ignore the queue since it won't see
	 * an updated idx.
	 */
	mb();

	return used_elem;
}

u16 virt_queue__get_iov(struct vring_virtqueue *vq, struct iovec iov[], u16 *out, u16 *in)
{
	struct vring_desc *desc;
	u16 head, idx;

	idx = head = virt_queue__pop(vq);
	*out = *in = 0;

	do {
		desc				= virt_queue__get_desc(vq, idx);
		iov[*out + *in].iov_base	= (void *)desc->addr;
		iov[*out + *in].iov_len		= desc->len;
		if (desc->flags & VRING_DESC_F_WRITE)
			(*in)++;
		else
			(*out)++;
		if (desc->flags & VRING_DESC_F_NEXT)
			idx = desc->next;
		else
			break;
	} while (1);

	return head;
}

/* in and out are relative to guest */
u16 virt_queue__get_inout_iov(struct vring_virtqueue *vq, struct iovec in_iov[],
				struct iovec out_iov[], u16 *in, u16 *out)
{
	u16 head, idx;
	struct vring_desc *desc;

	idx = head = virt_queue__pop(vq);
	*out = *in = 0;
	do {
		desc = virt_queue__get_desc(vq, idx);
		if (desc->flags & VRING_DESC_F_WRITE) {
			in_iov[*in].iov_base = (void *)desc->addr;
			in_iov[*in].iov_len = desc->len;
			(*in)++;
		} else {
			out_iov[*out].iov_base = (void *)desc->addr;
			out_iov[*out].iov_len = desc->len;
			(*out)++;
		}
		if (desc->flags & VRING_DESC_F_NEXT)
			idx = desc->next;
		else
			break;
	} while (1);
	return head;
}
