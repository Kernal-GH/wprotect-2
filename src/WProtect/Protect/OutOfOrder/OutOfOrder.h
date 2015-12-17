#ifndef CODEINFOSTRCUT_H
#define CODEINFOSTRCUT_H
#include <CodeInfoStruct.h>
#endif

#include <WPStruct.h>

#include <udis86.h>

/*
typedef struct _CODE_INFORMATION_
{
	unsigned char * buf; //���뻺����
	unsigned long  size; //��С
	unsigned long base; // ��ַ
}CodeInformation,*pCodeInformation;
*/


	
class OutOfOrder
{
 public:
	 OutOfOrder();
	 ~OutOfOrder();
public:
	 pCodeInformation code_out_of_order(pCodeInformation info,unsigned long imagebase); //��һ������������Ĵ�����Ϣ  �ڶ���������ʾҪ�Ѵ����ض�λ������
	 pInstructionBlockList m_InstructionBlockHead;
	 pInstructionBlockList add_instruction_block_list();   //�����յĳ����
	 pInstructionBlockList add_instruction_block_list(pInstructionList instruction);  //��������鲢����instructionָ���ʼ��List
	 pInstructionList add_instruction_list(pInstructionBlockList block,ud_t *pobj);  //��block�����ָ��

	 pInstructionList add_instruction_list(pInstructionList instruction,ud_t *pobj);  //��block�����ָ��

	 void clean_instruction_list(pInstructionList head);
	 void clean_instruction_block_list();

	 pCodeInformation build_block(pInstructionBlockList block,pCodeInformation info); //��һ��������  �ڶ�������  һ���յĺ���base��pCodeInformation
	 pCodeInformation code_recombine(pCodeInformation info);
	 unsigned int m_block_max;
	 template <class T>  T * recombine(T * t,int nSize);
	 pInstructionBlockList get_instruction_block_list(int id);
	 unsigned long **m_addr_table;//[][3] [][0]Ϊoldaddr [][1]Ϊnewaddr [][2]size [][3]id
	// unsigned long m_addr_table_size;
	 pCodeInformation build_reloc_jcc(pInstructionBlockList block,pCodeInformation info);
	 unsigned long get_old_addr_to_new_addr(unsigned long oldaddr);  //�����ϵ�ַ ��ȡ�µ�ַ

	 unsigned char *m_codebuf;
};
